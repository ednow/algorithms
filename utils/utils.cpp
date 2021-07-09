//
// Created by ednow on 2021/7/1.
//

#include   <string>
#include   <iostream>
#include <vector>
#include <regex>

using   namespace   std;
// python.replace()循环替换
string&   replace_all(string&   str, const  string&  old_value, const  string&  new_value)
{
 while(true)
{
     string::size_type   pos(0);
     if(   (pos=str.find(old_value)) != string::npos   )
      {
   str.replace(pos,old_value.length(),new_value);
}
     else  { break; }
 }
 return   str;
}


// python.replace(step=1) 只替换一次
string&   replace_all_distinct(string&   str, const  string&  old_value, const   string&   new_value)
{
 for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())
 {
     if(   (pos=str.find(old_value,pos)) != string::npos   )
      {
   str.replace(pos,old_value.length(),new_value);
}
     else  { break; }
 }
 return   str;
}


// python.split
vector<string>
split(string text, const string& delimiter){
    std::regex ws_re(delimiter);
    return vector<string>(std::sregex_token_iterator(text.begin() ,text.end(),ws_re,-1),std ::sregex_token_iterator());
}


// python.join
string
join(std::vector<std::string> strings, const string& delimiter){


    std::ostringstream imploded;
    std::copy(strings.begin(), strings.end(),
  std::ostream_iterator<std::string>(imploded, delimiter.c_str()));
    return imploded.str();
}