#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include "order_book.h"
#include<iostream>
#include "order_book.h"
#include<unordered_set>

class StockExchange {
public:
    static StockExchange& set_connection();
    bool receive_order(const ClientOrder& client_order);
    const double get_last_traded_price(std::string ticker) const;
private:
    StockExchange();
    void init_ticker(const std::string& ticker);
    const std::string get_randomized_order_id();
    const std::string ensure_order_id_uniqueness(const std::string& order_id);
    std::unordered_set<std::string> all_order_id_set;
    std::unordered_map<std::string, OrderBook> ticker_specific_ob; //ticker specific orderbook
};