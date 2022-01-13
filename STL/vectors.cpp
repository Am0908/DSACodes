// vector is used as a dynamic array..

#include <iostream>
#include <vector>
using namespace std;



int main()
{
    // vector<int> *vp =  new vector<int>();
    vector <int> v;
    v.push_back(10); //to insert an element.
    v.push_back(20);
    v.push_back(25);
    v.push_back(40);
    v.push_back(50);

    // use push_back to insert an element..don't insert any element directly.

    /* we can access the elements one by one using cout
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v.at(2)<<endl;
    cout<<"size:"<<v.size()<<endl;
    cout<<v.at(3)<<endl;
    cout<<v.at(4)<<endl;
    cout<<"size:"<<v.size()<<endl;
    cout<<v.at(10)<<endl;*/

    /* using .at() is safer than using square brackets.
    it gives us error if we try to access any out of range index but [] doesn't. */

    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;

    // to remove the last element
    v.pop_back();

    // to know the capacity of the vector array we can use the below function.
    cout<<"capacity: "<<v.capacity()<<endl;
    //size
    cout<<"size: "<<v.size();
    return 0;
}
