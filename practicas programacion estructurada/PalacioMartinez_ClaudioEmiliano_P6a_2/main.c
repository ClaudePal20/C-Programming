#include <stdio.h>
#include <stdlib.h>
float CelsiusAKelvin(float temp);
float CelsiusAFahrenheit(float temp);
float FahrenheitACelsius(float temp);
float FahrenheitAKelvin(float temp);
float KelvinACelsius(float temp);
float KelvinAFahrenheit(float temp);
int main()
{
    float temp,fahrenheit,kelvin,celsius;
    int opc;
    printf("Dame la temperatura:\n");
    scanf("%f",&temp);
    printf("\nQue tipo de temperatura es? \n1. Celsius\n2. Fahrenheit\n3.Kelvin\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            fahrenheit = CelsiusAFahrenheit(temp);
            kelvin = CelsiusAKelvin(temp);
            printf("Conversion Celsius a Fahrenheit y Kelvin nos da: \n%f grados Celsius a Fahrenheit son: %f\n%f grados Celsius a Kelvin son: %f",temp, fahrenheit, temp, kelvin);
            break;
        case 2:
            celsius = FahrenheitACelsius(temp);
            kelvin = FahrenheitAKelvin(temp);
            printf("Conversion Fahrenheit a Celsius y Kelvin nos da: \n%f grados Fahrenheit a Celsius son: %f\n%f grados Fahrenheit a Kelvin son: %f",temp, celsius, temp, kelvin);
            break;
        case 3:
            celsius = KelvinACelsius(temp);
            fahrenheit = KelvinAFahrenheit(temp);
            printf("Conversion Kelvin a Celsius y Kelvin nos da: \n%f grados Kelvin a Celsius son: %f\n%f grados Kelvin a Fahrenheit son: %f",temp, celsius, temp, fahrenheit);
            break;
        default:
            printf("Opcion no existente");
            break;
    }
    return 0;
}
float CelsiusAFahrenheit(float temp){
    return temp*1.8+32;
}
float CelsiusAKelvin(float temp){
    return temp+273.15;
}
float FahrenheitACelsius(float temp){
    return (temp-32)/(1.8);
}
float FahrenheitAKelvin(float temp){
    return (temp-32)*(0.5555555)+273.15;
}
float KelvinACelsius(float temp){
    return (temp-273.15);
}
float KelvinAFahrenheit(float temp){
    return 1.8*(temp-273.15)+32;
}
