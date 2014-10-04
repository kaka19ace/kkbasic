
#include <kkbasic/common.h>
#ifndef KKBASIC_EXTERND_API_H
#define KKBASIC_EXTERND_API_H 

void replace(string &target, string search, string replacement) {
        if (search == replacement)
                return;
        if (search == "")
                return;
        string::size_type i = string::npos;
        string::size_type lastPos = 0;
        while ((i = target.find(search, lastPos)) != string::npos) {
                target.replace(i, search.length(), replacement);
                lastPos = i + replacement.length();
        }
}

void split(const std::string &s, const std::regex &r, std::vector<std::string> &v)
{
    auto rit = std::cregex_token_iterator(s.data(), s.data() + s.length(), r, -1);
    auto rend = std::cregex_token_iterator();
    v.clear();
    while(rit != rend)
    {
        v.push_back(*rit);
        ++rit;
    }
}

#endif // KKBASIC_EXTEND_API_H 
