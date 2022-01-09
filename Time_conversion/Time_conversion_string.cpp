#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
   int size = s.length();
   if(s[size-2] == 'A'){
       string hh = s.substr(0,2);
       int h = stoi(hh);
       if(h == 12){
           string newh = "00";
           string newtime = newh.append(s.substr(2,6));
           return newtime;
       }
       else{
           return s.substr(0, size-2);
       }
   }
   else{
       string hh = s.substr(0,2);
       int h = stoi(hh);
       if(h == 12){
           return s.substr(0, size-2);
       }
       else{
           int inpm = h+12;
           string newh = to_string(inpm);
           string newtime = newh.append(s.substr(2,6));
           return newh;
       }
   }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

