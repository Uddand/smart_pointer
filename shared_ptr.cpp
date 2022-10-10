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
shared_ptr<biodata>mptr1;
{

   shared_ptr<biodata>mptr1(new biodata("Uddand",22));
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   mptr1->display();
   cout<<"mptr1 ref_count:"<<mptr1.use_count()<<endl;
   shared_ptr<biodata>mptr2=mptr1;  
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;
   mptr2->display();
   cout<<"mptr2 ref_count:"<<mptr2.use_count()<<endl;
   mptr1=move(mptr2);
   cout<<"mptr1 addr:"<<mptr1.get()<<endl;
   cout<<"mptr2 addr:"<<mptr2.get()<<endl;
   cout<<"mptr1 ref_count:"<<mptr1.use_count()<<endl;
   cout<<"mptr2 ref_count:"<<mptr2.use_count()<<endl;
   mptr1->display();
   mptr1.reset(new biodata("Saheb",23));
   cout<<"ref_count:"<<mptr1.use_count()<<endl;
   mptr1->display();
}
  cout<<"ref_count mptr1:"<<mptr1.use_count()<<endl;
   return 0;
}