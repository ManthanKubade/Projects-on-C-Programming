#include <stdio.h>

struct Weather {
    int day;
    float temperature;
    float humidity;
};

int main() {
    int n;
    float avgTemp = 0, maxTemp, minTemp;

    printf("Enter number of days: ");
    scanf("%d", &n);

    struct Weather w[n];

    for(int i = 0; i < n; i++) {
        printf("\nDay %d\n", i+1);
        w[i].day = i + 1;

        printf("Enter Temperature (°C): ");
        scanf("%f", &w[i].temperature);

        printf("Enter Humidity (%%): ");
        scanf("%f", &w[i].humidity);

        avgTemp += w[i].temperature;
    }

    avgTemp /= n;
    maxTemp = minTemp = w[0].temperature;

    for(int i = 1; i < n; i++) {
        if(w[i].temperature > maxTemp)
            maxTemp = w[i].temperature;

        if(w[i].temperature < minTemp)
            minTemp = w[i].temperature;
    }

    printf("\n--- Weather Report ---\n");
    printf("Average Temperature: %.2f °C\n", avgTemp);
    printf("Maximum Temperature: %.2f °C\n", maxTemp);
    printf("Minimum Temperature: %.2f °C\n", minTemp);

    // Simple forecast logic
    if(avgTemp > 30)
        printf("Forecast: Hot weather expected ☀\n");
    else if(avgTemp > 20)
        printf("Forecast: Pleasant weather 🌤\n");
    else
        printf("Forecast: Cold weather ❄\n");

    return 0;
}
