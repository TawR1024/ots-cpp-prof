#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

typedef std::tuple<u_int32_t, u_int32_t, u_int32_t, u_int32_t> IPv4Adress;

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

IPv4Adress stringToIPV4 (const std::string str)
{
    auto       parts = split (str, '.');
    IPv4Adress ip =
        std::make_tuple (std::stoi (parts[0]), std::stoi (parts[1]), std::stoi (parts[2]), std::stoi (parts[3]));
    return ip;
}

std::ostream& operator<< (std::ostream& os, const IPv4Adress& ip)
{
    return os << std::get<0> (ip) << "." << std::get<1> (ip) << "." << std::get<2> (ip) << "." << std::get<3> (ip);
}

int main (int argc, char const* argv[])
{
    try
    {
        std::vector<IPv4Adress> ip_pool;

        for (std::string line; std::getline (std::cin, line);)
        {
            std::vector<std::string> v = split (line, '\t');
            ip_pool.push_back (stringToIPV4 (v.at (0)));
        }

        // TODO reverse lexicographically sort

        // for (auto ip = ip_pool.cbegin (); ip != ip_pool.cend (); ++ip)
        // {
        //     for (auto ip_part = ip->cbegin (); ip_part != ip->cend (); ++ip_part)
        //     {
        //         if (ip_part != ip->cbegin ())
        //         {
        //             std::cout << ".";
        //         }
        //         std::cout << *ip_part;
        //     }
        //     std::cout << std::endl;
        // }
        for (auto ip = ip_pool.cbegin (); ip != ip_pool.cend (); ++ip)
        {
            std::cout << *ip << std::endl;
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

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
