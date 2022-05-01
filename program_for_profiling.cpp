#include <cpr/cpr.h>

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>

// Link to the big text file
const std::string FILE_URL = "https://github.com/python/cpython/archive/refs/tags/v3.11.0a7.tar.gz";

int fibonacci(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

void print_fibonacci(int counter)
{
    std::vector<int> vec;
    for (int i = 0; i < counter; i++)
    {
        vec.push_back(fibonacci(i));
    }
    for (auto value : vec)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Create function that sleeps for 5 seconds and than prints how many seconds passed
void sleep_and_print(int n)
{
    std::cout << "Sleeping for " << n << " seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "Done sleeping" << std::endl
              << std::endl;
}

// Create function that writes string to file character by character
// sync with file on every write.
void write_to_file()
{
    std::cout << "Writting sting into the file " << std::endl;
    auto start = std::chrono::system_clock::now();

    std::ofstream file;
    file.open("file.txt");
    const int CounterTarget = 300000;
    for (int counter = 0; counter < CounterTarget; ++counter)
    {
        file << counter << " ";
        file.flush();
    }
    file.close();

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - start;
    std::cout << "Done writting string into the file. Time: " << elapsed_seconds.count() << "s" << std::endl;
}

// Function that downloads text file from the internet, given the url string using libcurl.
// Text file should be downloaded to the current directory.
void download_text_file(std::string url)
{
    std::cout << "Downloading text file from the internet" << std::endl;
    auto start = std::chrono::system_clock::now();

    cpr::Response r = cpr::Get(cpr::Url{url});
    std::cout << "Downloaded bytes: " << r.downloaded_bytes << std::endl;

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - start;
    std::cout << "Done downloading text file from the internet. Time: " << elapsed_seconds.count() << "s" << std::endl;
}

int main()
{
    print_fibonacci(30);
    sleep_and_print(5);
    write_to_file();
    download_text_file(FILE_URL);
    return 0;
}