#define _USE_MATH_DEFINES
#include <cmath>

#include <cfloat>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

double to_double(std::string& temp_string)
{
    temp_string.replace(temp_string.find(','), 1, ".");

    const std::string temp_const_string = temp_string.data();
    double temp_double = stod(temp_const_string);

    return temp_double * (M_PI / 180);
}

double distance(const double& my_lon, const double& my_lat, const double& other_lon, const double& other_lat)
{
    return sqrt(pow((other_lon - my_lon) * cos((my_lat + other_lat) / 2), 2) + pow(other_lat - my_lat, 2)) * 6371;
}

int main()
{
    std::string lon, lat, best_name;
    int n;
    double best_distance = DBL_MAX;

    std::cin >> lon; std::cin.ignore();
    std::cin >> lat; std::cin.ignore();
    std::cin >> n; std::cin.ignore();

    double lon_d = to_double(lon), lat_d = to_double(lat);

    for (int i = 0; i < n; i++)
    {
        std::string defib, temp_string;
        std::vector<std::string> temp_vector(6);
        int j = 0;

        getline(std::cin, defib);

        std::istringstream temp_input(defib);

        while (getline(temp_input, temp_string, ';'))
        {
            temp_vector[j] = temp_string;
            j++;
        }

        double defib_lon = to_double(temp_vector[4]), defib_lat = to_double(temp_vector[5]);

        if (distance(lon_d, lat_d, defib_lon, defib_lat) <= best_distance)
        {
            best_distance = distance(lon_d, lat_d, defib_lon, defib_lat);
            best_name = temp_vector[1];
        }
    }

    std::cout << best_name << std::endl;
}