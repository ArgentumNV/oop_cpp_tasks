#include "../include/Parser.hpp"

#include <format>

namespace parser
{
    int pars_txt_to_csv(std::string txt_name, std::string csv_name)
    {
        std::ifstream txt{txt_name};
        if (!txt.is_open())
        {
            std::cerr << "Can not open " << txt_name << " file\n";
            return 1;
        }

        std::ofstream csv{csv_name};
        if (!csv.is_open())
        {
            std::cerr << "Can not open " << csv_name << " file\n";
            return 2;
        }

        std::list<std::string> list_of_lines{};
        std::string buffer{};
        while (std::getline(txt, buffer))
        {
            for (char &c : buffer)
            {
                if (std::ispunct(static_cast<unsigned char>(c)))
                    c = ' ';
            }
            list_of_lines.push_back(buffer);
        }
        txt.close();

        std::map<std::string, int> words_freq{};
        int cnt_all_words{};
        for (const std::string &str : list_of_lines)
        {
            std::istringstream stream{str};
            std::string word{};

            while (stream >> word)
            {
                words_freq[word]++;
                cnt_all_words++;
            }
        }

        csv << std::fixed << std::setprecision(2);
        for (auto it = words_freq.rbegin(); it != words_freq.rend(); it++)
        {
            double freq = static_cast<double>(it->second) / cnt_all_words;
            csv << it->first << ", " << it->second << ", " << freq * 100 << '\n';
        }
        csv.close();

        return 0;
    }
}