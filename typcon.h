#ifndef _TYPCON_H_
#define _TYPCON_H_

struct coefficients {
        double a;
        double b;
        double c;
};

struct answers {
        double x1;
        double x2;
        int n_roots;
};

struct equation_parametrs {
        struct coefficients coef;
        struct answers ans;
};

const double PREDEL = pow(10, -DBL_DIG);

const int standart_return = 1;
enum number_of_roots {
        inf_roots = -1,
        no_roots,
        one_root,
        two_roots,
        no_calculate_err
};

enum compare {
        less = -1,
        equal,
        more,
        no_compare_err = 3
};

enum continue_sol {
        no=0,
        yes=1
};

#endif
