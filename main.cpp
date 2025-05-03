#include <iostream>
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    static_cast<std::string*>(userp)->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main() {
    system("chcp 65001 > nul");
    std::cout << "Введіть назву країни: ";
    std::string country;
    std::getline(std::cin, country);

    std::string url = "https://restcountries.com/v3.1/name/" + country;
    CURL* curl = curl_easy_init();
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    auto j = json::parse(response);
    if (!j.is_array() || j.empty()) {
        std::cerr << "Країну не знайдено\n";
        return 1;
    }

    auto& countryObj = j[0];
    std::string name    = countryObj["name"]["common"];
    std::string capital = countryObj["capital"][0];
    std::string region  = countryObj["region"];

    std::cout << "\nРезультат для країни: " << name
              << "\nСтолиця: "   << capital
              << "\nРегіон: "    << region
              << "\n";
    return 0;
}
