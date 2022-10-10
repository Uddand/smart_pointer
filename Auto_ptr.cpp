#include <iostream>
#include <memory>
using namespace std;
class biodata {
     string s;int age;
    public:
    biodata(string str1,int n1):s(str1),age(n1){}
    void display() {
        cout<<"string:"<<s<<" "<<"num :"<<age<<endl;
    }
    
};
int main()
{
   auto_ptr<biodata>mptr1(new biodata("Uddand",22));
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;//mptr1 get address
   mptr1->display();//calling
   auto_ptr<biodata>mptr2=mptr1;//c-str:mptr2 points to object,mptr1 is nullptr  
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;//mptr1 is nullptr
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;//mptr2 get ownership,mptr2 get address
   mptr2->display();//calling
   mptr1=mptr2;//copy-assignment mptr1 is point to object,mptr2 is nullptr
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;//get ownership mptr1 get address
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;// mptr2 is nullptr
   return 0;
}
