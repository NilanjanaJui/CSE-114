/*
Write a c++ program 

Document1= 'the best data science course'
Document2= 'data science is popular'
D1=[1,1,1,1,1,0,0]
D2=[0,0,1,1,0,1,1]

D1*D2= 1*0+1*0+1*1+1*1+1*0+0*1+0*1=2

||D1||=sqrt(1^2+1^2+1^2+1^2+1^2+0^2+0^2)= sqrt(5)
||D1||=sqrt(0^2+0^2+1^2+1^2+0^2+1^2+1^2)= sqrt(4)

similarity(D1,D2)= (D1*D2)/(||D1||||D2||) = 2/(sqrt(5)*sqrt(4)) = 2/sqrt(20) = 0.44721

The angle between the vectors is calculated as:


cos(@)= 0.44721
@= arccos(0.44721) = 63.435

using namespace std;
not using sturcture,
not using multiple functions
using vector, map, bits/stdc++.h
*/

#include <iostream>
#include <map>
#include <sstream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

int main() 
{
    string Document1 = "the best data science course";
    string Document2 = "data science is popular";

    map<string, int> D1, D2;
    stringstream ss1(Document1), ss2(Document2);
    string word;
    while (ss1 >> word) {
        D1[word]++;
    }
    while (ss2 >> word) {
        D2[word]++;
    }
    

    int dotProduct = 0;
    for (auto it = D1.begin(); it != D1.end(); ++it) {
        dotProduct += it->second * D2[it->first];
    }

    double magD1 = 0, magD2 = 0;
    for (auto it = D1.begin(); it != D1.end(); ++it) {
        magD1 += pow(it->second, 2);
    }
    for (auto it = D2.begin(); it != D2.end(); ++it) {
        magD2 += pow(it->second, 2);
    }
    magD1 = sqrt(magD1);
    magD2 = sqrt(magD2);

    double similarity = dotProduct / (magD1 * magD2);

    double angle= (acos(similarity))*(180/M_PI);

    cout << "Dot Product: " << dotProduct << endl;
    cout << "Magnitude of D1: " << magD1 << endl;
    cout << "Magnitude of D2: " << magD2 << endl;
    cout << "Similarity: " << similarity << endl;
    cout << "Cosine angle: " << angle << endl;


    return 0;

}
