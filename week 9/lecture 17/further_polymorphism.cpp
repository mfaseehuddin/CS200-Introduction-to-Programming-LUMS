#include <iostream>
using namespace std;

// class topic: polymorphism
// we will have a canvas of size 3x4 and we will draw a text in different positions on the canvas
// we will have a base class called shape and a derived class called text
// the base class will have a pure virtual function called draw
// the derived class will override the draw function

// for this we need to import iomanip
#include <iomanip>

bool DEBUG = 1;
int WIDTH = 20;
// shape types: Circle, Rectangle
// representation of the canvas: 2D array of characters

// Types of objects:
// Shape:
// Circle, Rectangle

// inheritance diagram:
/*
                Shape
                /   \
               /     \
              /       \
             /         \
            /           \
           /             \
        Circle          Rectangle
        Functions:      Functions:
            draw()          draw()

*/

// 2D matrix
/*
Diagram:

_________________________
|Shape* | B     | C     |
|_______|_______|_______|
| B     | C     |NULLPTR|
|_______|_______|_______|
|NULLPTR| C     |NULLPTR|
|_______|_______|_______|

*/

// if we define a pure virtual function in private scope of the base class, then the class will become an abstract class and we cannot instantiate it.
// we can not also override the pure virtual function in the derived class.
// smol example
class Base
{
private:
    virtual void print() = 0;
};
class Derived : public Base
{
public:
    void print()
    {
        cout << "print(): Derived" << endl;
    }
};
// what will happen?
// the base class will become an abstract class and we cannot instantiate it.
// we can not also override the pure virtual function in the derived class.
//  Base *b = new Derived();//is this valid now?->no
//  b->print();//is this valid now?->no

// defining the abstract shape class
class Shape
{
protected:
    string symbol;
    int pos_x;
    int pos_y;

public:
    // pure virtual function
    virtual void draw() { cout << setw(WIDTH) << "X"; }
    // destructors
    ~Shape()
    {
        if (DEBUG)
            cout << "Destructor: Shape" << endl;
    }
};

// defining the circle class
class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int radius)
    {
        //circle character -> o
        this->symbol = "O";
        this->radius = radius;
    }
    void draw() { cout << setw(WIDTH) << symbol; }
    // destructor
    ~Circle()
    {
        if (DEBUG)
            cout << "Destructor: Circle" << endl;
    }
};

// defining the rectangle class
class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int width, int height)
    {
        //square character -> █
        this->symbol = "[]";
        this->width = width;
        this->height = height;
    }
    void draw() { cout << setw(WIDTH) << symbol; }
    // destructor
    ~Rectangle()
    {
        if (DEBUG)
            cout << "Destructor: Rectangle" << endl;
    }
};

// class Triangle : public Shape
// {
// private:
//     int width;
//     int height;

// public:
//     Triangle(int width, int height)
//     {
//         this->symbol = "▲";
//         this->width = width;
//         this->height = height;
//     }
//     void draw() { cout << setw(WIDTH) << symbol; }
//     // destructor
//     ~Triangle()
//     {
//         if (DEBUG)
//             cout << "Destructor: Triangle" << endl;
//     }
// };

//now we make a canvas class
class Canvas
{
private:
    int width;
    int height;
    Shape ***canvas;

public:
    //constructor
    Canvas(int width, int height)
    {
        this->width = width;
        this->height = height;
        // allocating memory for the canvas
        canvas = new Shape **[width];
        for (int i = 0; i < width; i++)
        {
            canvas[i] = new Shape *[height];
            for (int j = 0; j < height; j++)
            {
                canvas[i][j] = nullptr;
            }
        }
    }
    //destructor
    ~Canvas()
    {
        if (DEBUG)
            cout << "Destructor: Canvas" << endl;
        // deallocate memory
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                delete canvas[i][j];
            }
            delete[] canvas[i];
        }
        delete[] canvas;
    }
    // add Random shapes to the canvas
    void addRandomShapes()
    {
        // add max random shapes to the canvas in all positions
        int max_shapes = width * height;
        for(int r = 0; r < width; r++){
            for(int c = 0; c < height; c++){
                int random_shape = rand() % 2;
                if(random_shape == 0){
                    canvas[r][c] = new Circle(1);
                }
                else if(random_shape == 1){
                    canvas[r][c] = new Rectangle(1, 1);
                }
                // else if(random_shape == 2){
                //     canvas[r][c] = new Triangle(1, 1);
                // }
            }
        }
    }

    void addShape(Shape *shape, int pos_x, int pos_y)
    {
        // add a shape to the canvas at a specific position
        if(canvas[pos_x][pos_y] == nullptr) delete canvas[pos_x][pos_y];

        canvas[pos_x][pos_y] = shape;
    }

    void draw()
    {
        // draw the canvas
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (canvas[i][j] == nullptr)
                {
                    cout << setw(WIDTH) << " ";
                }
                else
                {
                    canvas[i][j]->draw();
                }
            }
            cout << endl;
        }
    }

};




int main()
{
    // // creating the canvas
    // const int ROW = 3, COL = 4;
    // Shape *canvas[ROW][COL];
    // // initializing the canvas
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {
    //         canvas[i][j] = nullptr;
    //     }
    // }

    // ////////////////////////// stop code for 5 seconds
    // ////////////////////////// this_thread::sleep_for(chrono::seconds(5));

    // // adding the shapes to the canvas
    // if (DEBUG)
    // {
    //     // init srand
    //     // why did it work without this? -> because the srand function is called in the main function of the program
    //     srand(time(NULL));
    //     for (int r = 0; r < ROW; r++)
    //         for (int c = 0; c < COL; c++)
    //             // randomly set circle or rectangle
    //             if (rand() % 2 == 0)
    //                 canvas[r][c] = new Circle(rand() % 10);
    //             else
    //                 canvas[r][c] = new Rectangle(rand() % 10, rand() % 10);
    // }

    // // drawing the canvas
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {
    //         if (canvas[i][j] == nullptr)
    //         {
    //             cout << setw(WIDTH) << " ";
    //         }
    //         else
    //         {
    //             canvas[i][j]->draw();
    //         }
    //     }
    //     cout << endl;
    // }

    // // deleting the shapes
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {
    //         if (canvas[i][j] != nullptr)
    //         {
    //             delete canvas[i][j];
    //         }
    //     }
    // }




    //create a canvas
    Canvas canvas(3, 4);
    //add random shapes to the canvas
    canvas.addRandomShapes();
    //draw the canvas
    canvas.draw();



    return 0;
}