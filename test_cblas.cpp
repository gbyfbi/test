#include <stdio.h>
#include <stdlib.h>
#include <f2c.h>

extern "C" {
#include <clapack.h>
}
int main()
{
    integer m, n, incx, incy, leadingA;
    real alpha, beta;
    real * A, * x, * y;
    char * trans = "N";
    m = 4;
    n = 3;
    incx = 1;
    incy = 1;
    leadingA = m;
    alpha = 1.f;
    beta = 1.f;
    A = (real*)malloc(sizeof(real) * m * n);
    for(int i = 0; i < m * n; i++) {
        A[i] = 0.f;
    }
    A[0] = 10.0f;
    A[5] = 34.f;
    x = (real*)malloc(sizeof(real) * n);
    for(int i = 0; i < n; i++) {
        x[i] = 1.f;
    }
    y = (real*)malloc(sizeof(real) * m);
    for(int i = 0; i < m; i++) {
        y[i] = 0.f;
    }
    sgemv_(trans, &m, &n, &alpha, A, &leadingA, x, &incx, &beta, y, &incy);
    for(int i = 0; i < m; i++) {
        fprintf(stdout, "%f\n", y[i]);
    }
    return 0;
}
