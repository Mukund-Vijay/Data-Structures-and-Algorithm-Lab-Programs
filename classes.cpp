//To write a menu driven program to caluclate the area of square,cube,rectangle and cuboid using classes,dimensions are given by the user

#include <iostream>
using namespace std;

class Area
{
    private:
        float len,brea,hei;
    
    public:
        Area()
        {len=1.00;brea=1.00;hei=1.00;} 
        float get_len();
        float get_brea();
        float get_hei();
        void set_len(float);
        void set_brea(float);
        void set_hei(float);
        float area_sqaure();
        float area_cube();
        float area_rectangle();
        float area_cuboid();
};

int main()
{
    Area obj;
    cout<<"<=======Menu=======>\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n";
    int choice,menu;
    cout<<"Enter your choice : ";
    cin>>menu;

    while(menu>5 || menu<1)
    {
       cout<<"Invalid Choice!\n";
       cout<<"<=======Menu=======>\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n";
        cout<<"Enter a valid choice : ";
        cin>>menu; 
    } 

    while(menu!=5)
    {
        cout<<"Enter 1 to continue with the base dimensions or 2 to enter new dimensions : ";
        cin>>choice;

        while(choice>2 || choice<1)
        {
            cout<<"Invalid Choice!\n";
            cout<<"Enter 1 to continue with the base dimensions or 2 to enter new dimensions : ";
            cin>>choice;
        }
    
        float length=obj.get_len();
        float breadth=obj.get_brea();
        float height=obj.get_hei();

        if(menu==1)
        {
            if(choice==1)
            {
                cout<<"The base dimensions are:\nSide Length = "<<length<<" m\n";
                float area=obj.area_sqaure();
                cout<<"The Area of the Square = "<<area<<" m^2\n";
            }

            else
            {
                float temp_len;
                cout<<"Enter the Side Length : ";
                cin>>temp_len;
                obj.set_len(temp_len);
                cout<<"The dimensions are:\nSide Length = "<<temp_len<<" m\n";
                float area=obj.area_sqaure();
                cout<<"The Area of the Square = "<<area<<" m^2\n";
            }
        }

        if(menu==2)
        {
            if(choice==1)
            {
                cout<<"The base dimensions are:\nSide Length = "<<length<<" m\n";
                float area=obj.area_cube();
                cout<<"The Area of the Cube = "<<area<<" m^2\n";
            }

            else
            {
                float temp_len;
                cout<<"Enter the Side Length : ";
                cin>>temp_len;
                obj.set_len(temp_len);
                cout<<"The dimensions are:\nSide Length = "<<temp_len<<" m\n";
                float area=obj.area_cube();
                cout<<"The Area of the Cube = "<<area<<" m^2\n";
            }
        }

        if(menu==3)
        {
            if(choice==1)
            {
                cout<<"The base dimensions are:\nLength = "<<length<<" m\nBreadth = "<<breadth<<" m\n";
                float area=obj.area_rectangle();
                cout<<"The Area of the Rectangle = "<<area<<" m^2\n";
            }

            else
            {
                float temp_len,temp_brea,temp_hei;
                cout<<"Enter the Length : ";
                cin>>temp_len;
                cout<<"Enter the Breadth : ";
                cin>>temp_brea;
                obj.set_len(temp_len);
                obj.set_brea(temp_brea);
                cout<<"The dimensions are:\nLength = "<<temp_len<<" m\nBreadth = "<<temp_brea<<" m\n";
                float area=obj.area_rectangle();
                cout<<"The Area of the Rectangle = "<<area<<" m^2\n";
            }
        }

        if(menu==4)
        {
            if(choice==1)
            {
                cout<<"The base dimensions are:\nLength = "<<length<<" m\nBreadth = "<<breadth<<" m\nHeight = "<<height<<" m\n";
                float area=obj.area_cuboid();
                cout<<"The Area of the cuboid = "<<area<<" m^2\n";
            }

            else
            {
                float temp_len,temp_brea,temp_hei;
                cout<<"Enter the Length : ";
                cin>>temp_len;
                cout<<"Enter the Breadth : ";
                cin>>temp_brea;
                cout<<"Enter the Height : ";
                cin>>temp_hei;
                obj.set_len(temp_len);
                obj.set_brea(temp_brea);
                obj.set_hei(temp_hei);
                cout<<"The dimensions are:\nLength = "<<temp_len<<" m\nBreadth = "<<temp_brea<<" m\nHeight = "<<temp_hei<<" m\n";
                float area=obj.area_cuboid();
                cout<<"The Area of the Cuboid = "<<area<<" m^2\n";
            }
        }

        cout<<"<=======Menu=======>\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n";
        cout<<"Enter your choice : ";
        cin>>menu;

        while(menu>5 || menu<1)
        {
            cout<<"Invalid Choice!\n";
            cout<<"<=======Menu=======>\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n";
            cout<<"Enter a valid choice : ";
            cin>>menu; 
        }
    }
    
    return 0;
}

void Area::set_len(float temp_len)
{
    len=temp_len;
}

void Area::set_brea(float temp_brea)
{
    brea=temp_brea;
}

void Area::set_hei(float temp_hei)
{
    hei=temp_hei;
}

float Area::get_len()
{
    float temp=len;
    return temp;
}

float Area::get_brea()
{
    float temp=brea;
    return temp;
}

float Area::get_hei()
{
    float temp=hei;
    return temp;
}

float Area::area_sqaure()
{
    float temp_area=len*len;
    return temp_area;
}

float Area::area_cube()
{
    float temp_area=6*len*len;
    return temp_area;
}

float Area::area_rectangle()
{
    float temp_area=len*brea;
    return temp_area;
}

float Area::area_cuboid()
{
    float temp_area=2*(len*brea+brea*hei+hei*len);
    return temp_area;
}
