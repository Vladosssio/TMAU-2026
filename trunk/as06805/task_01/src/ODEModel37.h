#pragma once
#include "Model.h"
#include <cmath>

class ODEModel37 : public Model {
public:
    ODEModel37(double a, double b, double dt)
        : a_(a), b_(b), dt_(dt) {
        reset();
    }

    void reset() override { y_ = 0.0; }

    double step(double u) override {
        // dy/dt = -exp(a)*y + b*u (метод Эйлера)
        double dy = -std::exp(a_) * y_ + b_ * u;
        y_ = y_ + dt_ * dy;
        return y_;
    }

    const char* name() const override { return "Model 3.7 (ODE Exponential, Euler)"; }

private:
    double a_, b_, dt_;
    double y_ = 0.0;
};