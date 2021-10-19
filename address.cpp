// Copyright (c) 2021 D.B. Calitis All rights reserved
//
// Created by: Daria Bernice Calitis
// Created on: Oct 2021
// This program formats your mailing address

#include <iostream>
#include <string>
#include <algorithm>

std::string AddressFormatter(
    std::string fullName,
    int streetNumber,
    std::string streetName,
    std::string cityName,
    std::string provinceName,
    std::string postalCode,
    int apartmentNumber = -1) {
    // This function formats your address to a mailing address
    int stringLength;
    std::string mailingAddress;

    if (apartmentNumber != -1) {
        mailingAddress = (fullName + "\n" + std::to_string(apartmentNumber)
        + "-" + std::to_string(streetNumber) + " " + streetName + "\n" +
        cityName + " " + provinceName + "  " + postalCode);
    } else {
        mailingAddress = (fullName + "\n" + std::to_string(streetNumber)
        + " " + streetName + "\n" + cityName + " " +
        provinceName + "  " + postalCode);
    }
    // https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
    // #:~:text=To%20convert%20a%20complete%20string,function%20each%20of%20them%20i.e.&text=c%20%3D%20%3A%3Atoupper(c),
    // case%20std%3A%3Afor_each(data.
    // converts to uppercase
    std::for_each(mailingAddress.begin(), mailingAddress.end(),
    [](char & c) { c = ::toupper(c);});

    return mailingAddress;
    }

int main() {
    std::string inputFullName;
    std::string inputApartment;
    std::string inputApartmentNumberString;
    int inputApartmentNumber = -1;
    std::string inputStreetNumberString;
    int inputStreetNumber;
    std::string inputStreetName;
    std::string inputCity;
    std::string inputProvince;
    std::string inputPostalCode;

    std::cout << "This program formats your address to a mailing address"
    << std::endl;

    // input
    try {
        std::cout << "Enter your full name: ";
        getline(std::cin, inputFullName);

        std::cout << "Do you live in an apartment? (y/n): ";
        getline(std::cin, inputApartment);

        // convert string to upper case
        std::for_each(inputApartment.begin(), inputApartment.end(),
        [](char & c) { c = ::toupper(c);});
        if (inputApartment == "Y" || inputApartment == "YES") {
            std::cout << "Enter your apartment number: ";
            getline(std::cin, inputApartmentNumberString);
            // checks if the given apartment number is a number
            inputApartmentNumber = std::stoi(inputApartmentNumberString);
        }

        std::cout << "Enter your street number: ";
        getline(std::cin, inputStreetNumberString);
        // checks if the given street number is a number
        inputStreetNumber = std::stoi(inputStreetNumberString);

        std::cout <<
        "Enter your street name And type (Main St, Express Pkwy...): ";
        getline(std::cin, inputStreetName);

        std::cout << "Enter your city: ";
        getline(std::cin, inputCity);

        std::cout <<
        "Enter your province (as an abbreviation, ex: ON, BC..): ";
        getline(std::cin, inputProvince);

        std::cout << "Enter your postal code (A1B 2C3): ";
        getline(std::cin, inputPostalCode);

        // process & output
        std::cout << "" << std::endl;
        if (inputApartmentNumber != -1) {
            std::cout <<
            AddressFormatter(
                inputFullName,
                inputStreetNumber,
                inputStreetName,
                inputCity,
                inputProvince,
                inputPostalCode,
                inputApartmentNumber) << std::endl;
        } else {
            std::cout <<
            AddressFormatter(
                inputFullName,
                inputStreetNumber,
                inputStreetName,
                inputCity,
                inputProvince,
                inputPostalCode) << std::endl;
        }
    } catch (...) {
        std::cout << "\nInvalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
