#include <iostream>
#include <memory>
using namespace std;
class biodata {
     string s;int age;
    public:
    biodata(string str1,int n1):s(str1),age(n1){}
    void display() {
        cout<<"name:"<<s<<" "<<"age :"<<age<<endl;
    }
    
};
int main()
{
   unique_ptr<biodata>mptr1(new biodata("Uddand",22));
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   mptr1->display();
   unique_ptr<biodata>mptr2=move(mptr1);  
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;
   mptr2->display();
   mptr1=move(mptr2);
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;
    mptr1->display();
   return 0;
}