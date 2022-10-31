#include <stdio.h>

int main(void) {

    double value = 0;

    printf("\n==========WELCOME TO THE CURRENCY CONVERT0R!==========\n");

    printf("\nType a value to convert:\n");
     scanf("%lf", &value);

    /*based on values obtained 9/29 @ 10 a.m.*/
    const double usd = 1.00000 * value;
    const double gbp = 0.910121 * value;
    const double cad = 1.367994 * value;
    const double eur = 1.02758 * value;
    const double aud = 1.547634 * value;
    const double xmr = 0.00678501 * value;

    printf("\n\tusd\t\tgbp\t\tcad\t\teur\t\taud\t\txmr\n");

    printf("usd\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    value, (usd*value)/gbp, (usd*value)/cad, (usd*value)/eur, (usd*value)/aud, (usd*value)/xmr);

    printf("gbp\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    gbp, value, (gbp*value)/cad, (gbp*value)/eur, (gbp*value)/aud, (gbp*value)/xmr);

    printf("cad\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    cad, (cad*value)/gbp, value, (cad*value)/eur, (cad*value)/aud, (cad*value)/xmr);

    printf("eur\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    eur, (eur*value)/gbp, (eur*value)/cad, value, (eur*value)/aud, (eur*value)/xmr);

    printf("aud\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    aud, (aud*value)/gbp, (aud*value)/cad, (aud*value)/eur, value, (aud*value)/xmr);

    printf("xmr\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.10lf\n",
    xmr, (xmr*value)/gbp, (xmr*value)/cad, (xmr*value)/eur, (xmr*value)/aud, value);

    return 0;
}