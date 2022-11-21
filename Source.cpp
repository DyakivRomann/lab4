#include<iostream>
#include<fstream>
using namespace std;

class Cube
{
protected:

    int size;

public:
    Cube(int size)
    {
        this->size = size;
    }

    int VCube()
    {
        int vcube = size * size * size;
        return vcube;
    }

    int SCube()
    {
        int scube = size * size * 6;
        return scube;
    }

    void PrintCube()
    {
        cout << "V of Cube " << VCube() << "\nS of Cube " << SCube() << endl << endl;

    }

};


class Sphere
{
protected:

    int r;

public:
    Sphere(int r)
    {
        this->r = r;
    }

    float VSphere()
    {
        float vsphere = 4 / 3 * 3.14 * 2 * r * 2 * r * 2 * r;
        return vsphere;
    }

    float SSphere()
    {
        float ssphere = 4 * 3.14 * r * r;
        return ssphere;
    }

    void PrintSphere()
    {
        cout << "V of Sphere " << VSphere() << "\nS of Sphere " << SSphere() << endl << endl;

    }

};

class SphereInCube : public Cube, public Sphere
{
public:
    SphereInCube(int size, int r)
    {
        this->size = size;
        this->r = r;
    }


    void Check()
    {
        try
        {
            if (size != r * 2)
            {
                throw 0;
            }
            else
            {
                cout << "Figure can exist" << endl;
                ofstream info;
                info.open("Info.txt");

                info << "Info " << "\n\nV of Cube " << VCube() << "\nS of Cube " << SCube() << "\n\nV of Sphere " << VSphere() << "\nS of Sphere " << SSphere() << endl;

                info.close();
            }
        }
        catch (...)
        {
            cout << "Figure can not exist" << endl;
        }
    }

    void PrintAll()
    {
        cout << "\nFull info " << endl;
        PrintCube();
        PrintSphere();

    }

};

int main()
{
    Cube a(4);

    a.VCube();
    a.SCube();
    a.PrintCube();

    Sphere b(2);

    b.VSphere();
    b.SSphere();
    b.PrintSphere();

    SphereInCube c(4, 2);

    c.Check();
    c.PrintAll();

    system("pause");
    return 0;
}