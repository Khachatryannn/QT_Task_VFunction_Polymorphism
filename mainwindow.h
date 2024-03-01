#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};


class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14156 * radius * radius;
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        Rectangle rectangle(4.0, 7.0);
        Circle circle(3.0);

        printArea(&rectangle);
        printArea(&circle);
    }

    void printArea(const Shape* shape) {
        std::cout << "Area: " << shape->area() << std::endl;
    }
};
#endif // MAINWINDOW_H


