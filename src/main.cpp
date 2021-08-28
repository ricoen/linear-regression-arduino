#include <Arduino.h>
#include <ArduinoSTL.h>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<double> x = {1.1, 1.5, 2.2, 3.7, 5.6};
vector<double> y = {5.3, 7.1, 10.7, 18, 27};

double m = 0; // Slope
double b = 0; // Intercept
double alpha = 0.01; // Learning Rate
int iter = 20;

// Use linear regression formula y = m.x + b
// Use error formula error = p(i) - y(i)
// Use update the weights formula = b(t+1) = b(t) - alpha * error
// Use update the slope formula = m(t+1) = m(t) - alpha * error * x

vector<double> error;
double err;

bool custom_sort(double a, double b){
    double  a1 = abs(a-0);
    double  b1 = abs(b-0);
    
    return a1 < b1;
}

void gradient_descent() {
    for(int i=0; i<iter; i++){
        int index = i % 5;
        double Y_predict = b + m * x[index];
        err = Y_predict - y[index];
        b = b - alpha * err;
        m = m - alpha * err * x[index];
        error.push_back(err);
        cout << "b = " << b << " " << "m = " << m << " " << "error = " << err << endl;
    }
    sort(error.begin(), error.end(), custom_sort); //sorting based on error values
    cout<<"Final Values are: " << "b = " << b <<" " << "m = " << m << " "
    << "error = " << error[0] << endl;
    cout << endl;
}

void prediction(double X) {
    double predict = b + m * X;

    cout << "Y Prediction = " << predict << endl;
    cout << endl;
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    
    double sensor = 2.00;
    
    gradient_descent();
    prediction(sensor);
}

void loop() {
    // put your main code here, to run repeatedly:
}