#include<iostream>
#include<vector>
using namespace std;

template <class T>
int display(vector <T> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> vec1; //declaration of a vector
    int element, size;
    cout<<"Enter the size of the vector ";
    cin>>size;
    for(int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add in vector ";
        cin>>element;
        vec1.push_back(element);  //add element in vector
    }
    display(vec1);
    // vec1.pop_back(); //remove the last element of vector
    vector<int> :: iterator iter = vec1.begin(); //pointer to 1st element of vector
    vec1.insert(iter, 3, 12); // add 12 to beginning of vector 3 times
    display(vec1); 

    /* Ways to create a vector
    vector<int> vec2;   //zero length integer vector
    vector<char> vec3(4); //4-element character vector  
    vector<char> vec4(vec3); //4-element character vector from vec3
    vector<int> v(6,3); // 6-element integer vector of 3s

    display(vec2);
    display(vec3);
    display(vec4);
    display(v);
    */

    return 0;
}