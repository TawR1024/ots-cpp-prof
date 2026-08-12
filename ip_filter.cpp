#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

typedef std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> IPv4Address;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split (const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop  = str.find_first_of (d);
    while (stop != std::string::npos)
    {
        r.push_back (str.substr (start, stop - start));

        start = stop + 1;
        stop  = str.find_first_of (d, start);
    }

    r.push_back (str.substr (start));

    return r;
}

IPv4Address string_to_IPv4 (const std::string str)
{
    auto        parts = split (str, '.');
    IPv4Address ip =
        std::make_tuple (std::stoi (parts[0]), std::stoi (parts[1]), std::stoi (parts[2]), std::stoi (parts[3]));
    return ip;
}

std::ostream& operator<< (std::ostream& os, const IPv4Address& ip)
{
    return os << std::get<0> (ip) << "." << std::get<1> (ip) << "." << std::get<2> (ip) << "." << std::get<3> (ip);
}

std::vector<IPv4Address> filter_any (const std::vector<IPv4Address>& input, uint32_t filter)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == filter || std::get<1> (ip) == filter || std::get<2> (ip) == filter ||
            std::get<3> (ip) == filter)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

std::vector<IPv4Address> filter_by_first (const std::vector<IPv4Address>& input, uint32_t filter)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == filter)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

std::vector<IPv4Address> filter_by_first_and_second (const std::vector<IPv4Address>& input, uint32_t byte0f,
                                                     uint32_t byte1f)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == byte0f && std::get<1> (ip) == byte1f)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

void print (const std::vector<IPv4Address>& ip_pool)
{
    for (auto ip = ip_pool.cbegin (); ip != ip_pool.cend (); ++ip)
    {
        if (ip != ip_pool.cbegin ())
            std::cout << "\n";
        std::cout << *ip;
    }
}

int main (int argc, char const* argv[])
{
    try
    {
        std::vector<IPv4Address> ip_pool;

        for (std::string line; std::getline (std::cin, line);)
        {
            std::vector<std::string> v = split (line, '\t');
            ip_pool.push_back (string_to_IPv4 (v.at (0)));
        }

        // TODO reverse lexicographically sort
        std::sort (ip_pool.begin (), ip_pool.end (), std::greater<>{});
        print (ip_pool);
        std::cout << std::endl;

        // TODO filter by first byte and output
        // ip = filter(1)
        print (filter_by_first (ip_pool, 1));
        std::cout << std::endl;

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        print (filter_by_first_and_second (ip_pool, 46, 70));
        std::cout << std::endl;

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)
        print (filter_any (ip_pool, 46));
        std::cout << std::endl;

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what () << std::endl;
    }

    return 0;
}
