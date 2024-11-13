#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Read the sales data
    vector<unordered_map<string, string>> data;
    ifstream file("sales-data.txt");
    string line, header;

    // Check if the file opens successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    // Read header line
    getline(file, header);
    vector<string> headers;
    stringstream headerStream(header);
    string headerField;
    while (getline(headerStream, headerField, ',')) {
        headers.push_back(headerField);
    }

    // Read data lines
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        unordered_map<string, string> row;
        int i = 0;
        
        // Parse each field according to headers
        while (getline(ss, field, ',')) {
            if (i < headers.size()) {
                row[headers[i]] = field;
            }
            i++;
        }
        data.push_back(row);
    }
    file.close();

    // 1. Total sales of the store
    double total_sales = 0;
    for (const auto& row : data) {
        total_sales += stod(row.at("Total Price"));  // Use at() for safe access
    }
    cout << "Total sales of the store: " << total_sales << endl;

    // 2. Month wise sales totals
    unordered_map<string, double> month_sales;
    for (const auto& row : data) {
        string month = row.at("Date").substr(0, 7);  // Use "YYYY-MM" for month
        month_sales[month] += stod(row.at("Total Price"));
    }
    cout << "Month wise sales totals:" << endl;
    for (const auto& month_pair : month_sales) {
        cout << month_pair.first << ": " << month_pair.second << endl;
    }

    // 3. Most popular item (most quantity sold) in each month
    unordered_map<string, unordered_map<string, int>> popular_items;
    for (const auto& row : data) {
        string month = row.at("Date").substr(0, 7);
        string item = row.at("SKU");
        int quantity = stoi(row.at("Quantity"));
        popular_items[month][item] += quantity;
    }
    cout << "Most popular item (most quantity sold) in each month:" << endl;
    for (const auto& month_pair : popular_items) {
        const auto& month = month_pair.first;
        const auto& items = month_pair.second;
        string most_popular = max_element(items.begin(), items.end(),
                                          [](const auto& a, const auto& b) {
                                              return a.second < b.second;
                                          })->first;
        cout << month << ": " << most_popular << endl;
    }

    // 4. Items generating most revenue in each month
    unordered_map<string, unordered_map<string, double>> revenue_items;
    for (const auto& row : data) {
        string month = row.at("Date").substr(0, 7);
        string item = row.at("SKU");
        double revenue = stod(row.at("Total Price"));
        revenue_items[month][item] += revenue;
    }
    cout << "Items generating most revenue in each month:" << endl;
    for (const auto& month_pair : revenue_items) {
        const auto& month = month_pair.first;
        const auto& items = month_pair.second;
        string most_revenue = max_element(items.begin(), items.end(),
                                          [](const auto& a, const auto& b) {
                                              return a.second < b.second;
                                          })->first;
        cout << month << ": " << most_revenue << endl;
    }

    // 5. For the most popular item, find the min, max, and average number of orders each month
    for (const auto& month_pair : popular_items) {
        const auto& month = month_pair.first;
        const auto& items = month_pair.second;
        string most_popular = max_element(items.begin(), items.end(),
                                          [](const auto& a, const auto& b) {
                                              return a.second < b.second;
                                          })->first;

        vector<int> orders;
        for (const auto& row : data) {
            if (row.at("Date").substr(0, 7) == month && row.at("SKU") == most_popular) {
                orders.push_back(stoi(row.at("Quantity")));
            }
        }

        if (!orders.empty()) {
            cout << "For the most popular item \"" << most_popular << "\" in " << month << ":" << endl;
            cout << "  Min orders: " << *min_element(orders.begin(), orders.end()) << endl;
            cout << "  Max orders: " << *max_element(orders.begin(), orders.end()) << endl;
            cout << "  Average orders: " << accumulate(orders.begin(), orders.end(), 0.0) / orders.size() << endl;
        }
    }

    return 0;
}
