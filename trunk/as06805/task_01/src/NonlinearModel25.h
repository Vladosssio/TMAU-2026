#pragma once
#include "Model.h"
#include <cmath>

class NonlinearModel25 : public Model {
public:
    NonlinearModel25(double a, double b)
        : a_(a), b_(b) {
        reset();
    }

    void reset() override {
        y_ = 0.0;
    }

    double step(double u) override {
        // y_{tau+1} = a*y_{tau} + b * sign(u) * (1 - exp(-|u|))
        int sign_u = (u > 0) ? 1 : ((u < 0) ? -1 : 0);
        double y_next = a_ * y_ + b_ * sign_u * (1.0 - std::exp(-std::abs(u)));
        y_ = y_next;
        return y_;
    }

    const char* name() const override { return "Model 2.5 (Signum Friction)"; }

private:
    double a_, b_;
    double y_ = 0.0;
};