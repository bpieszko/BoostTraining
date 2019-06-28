#include <string>
#include <memory>
#include <cstdio>

#include <boost/scope_exit.hpp>

struct CloseFile
{
	void operator()(std::FILE *file)
	{
		std::fclose(file);
	}
};

void write_to_file(const std::string &s)
{
	std::unique_ptr<std::FILE, CloseFile> file{
		std::fopen("hello-world.txt", "a")
	};
	std::fprintf(file.get(), s.c_str());
}

void write_to_file_boost(const std::string &s) {
	std::FILE* file = std::fopen("hello-world.txt", "a");
	
	BOOST_SCOPE_EXIT(&file)
	{
		std::fclose(file);
		file = 0;
	} BOOST_SCOPE_EXIT_END

	std::fprintf(file, s.c_str());
}

int main()
{
	write_to_file_boost("Hello, ");
	write_to_file_boost("world!");
}
