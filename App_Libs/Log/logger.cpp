#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace boost::log;

typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;

int main() {
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

	boost::shared_ptr<std::ostream> stream{&std::clog, boost::null_deleter{}};
	sink->locked_backend()->add_stream(stream);

	core::get()->add_sink(sink);

	sources::logger lg;

	BOOST_LOG(lg) << "note";
	sink->flush();
}