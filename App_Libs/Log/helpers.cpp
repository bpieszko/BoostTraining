#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/core/null_deleter.hpp>
#include <iostream>
#include <iomanip>

using namespace boost::log;

BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(counter, "LineCounter", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "Timestamp", boost::posix_time::ptime)

typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;

int main() {
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{&std::clog, boost::null_deleter{}};

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(expressions::is_in_range(severity, 1, 3));
	sink->set_formatter(
		expressions::stream << std::setw(5) << counter << " - "
			<< severity << ": " << expressions::smessage << " ("
			<< expressions::format_date_time(timestamp, "%H:%M:%S") << ")"
	);

	core::get()->add_sink(sink);
	core::get()->add_global_attribute("LineCounter", attributes::counter<int>{});

	sources::severity_logger<int> lg;

	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	{
		BOOST_LOG_SCOPED_LOGGER_ATTR(lg, "Timestamp", attributes::local_clock{});
		BOOST_LOG_SEV(lg, 2) << "error";
	}
	BOOST_LOG_SEV(lg, 2) << "another error";
	sink->flush();
}