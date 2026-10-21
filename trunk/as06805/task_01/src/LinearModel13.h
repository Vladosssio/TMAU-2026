#pragma once
#include "Model.h"

class LinearModel13 : public Model {
public:
    LinearModel13(double a1, double a2, double b)
        : a1_(a1), a2_(a2), b_(b) {
        reset();
    }

    void reset() override {
        y_ = 0.0;
        yPrev_ = 0.0;
    }

    double step(double u) override {
        // y_{tau+1} = a1*y_{tau} + a2*y_{tau-1} + b*u_{tau}
        double y_next = a1_ * y_ + a2_ * yPrev_ + b_ * u;
        yPrev_ = y_;
        y_ = y_next;
        return y_;
    }

    const char* name() const override { return "Model 1.3 (Second-Order Inertial)"; }

private:
    double a1_, a2_, b_;
    double y_ = 0.0;
    double yPrev_ = 0.0;
};