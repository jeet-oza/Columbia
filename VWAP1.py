#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr 19 18:13:12 2019

@author: jeetoza
"""

import pandas as pd
from pandas import ExcelWriter
from pandas import ExcelFile
import os
import datetime
import matplotlib.pyplot as plt
import numpy as np

def VWAP_Trade_Cost(Date, Time, shares, ticker, pct):
    total_shares = shares
    trades = []
    total_price = 0
    curr_price = []
    format = "%Y%m%d %H%M"

    while shares > 0 :
        func = lambda x : pd.to_datetime( Date + " " + str(x.hour) + str(x.minute), format=format)
        dateTime = pd.to_datetime(Date + " " + Time, format=format)
        start = pd.to_datetime(Date + " 930", format=format)
        end = pd.to_datetime(Date + " 1600", format=format)
        file = "S&P500 - Q4 2018/allstocks_" + Date + "/table_" + ticker + ".csv"
        if (os.path.exists(file)) & (Date != "20181224"):
            data = pd.read_csv(file, header = None,
                               names=["Date", "Time", "Open", "High", 'Low', "Close", "Volume", "a", "b", "c"],
                               parse_dates=[['Date', 'Time']]) 
            data["DateTime"] = pd.to_datetime(data.Date_Time, format=format)
            data["Mid"] = (data["High"] + data["Low"] + data["Open"] + data["Close"]) / 4
            data = data[["DateTime", "Open", "High", "Low", "Close", "Mid", "Volume"]]
            filtered_data = data[(data.DateTime>=dateTime) & (data.DateTime >= start) & (data.DateTime <= end)]
            filtered_data = filtered_data.reset_index(drop=True)
            curr_price.append(filtered_data.Mid[0])

            for row in filtered_data.itertuples():
                if np.isnan(row.Volume):
                    Volume =  0 
                else:
                    Volume = row.Volume
                traded_Volume = min(int(Volume * pct), shares)
                price = row.Mid
                trades.append({"Time" : row.DateTime, "Volume" : traded_Volume, "Price" : price})
                total_price += traded_Volume * price
                shares -= traded_Volume
                if(shares == 0):
                    break
        d = dateTime + datetime.timedelta(days = 1)
        if d.year >2018 :
            break;
        Date = d.strftime("%Y%m%d")
        Time = " 930"
    Price_Per_Share = total_price / (total_shares - shares)
    rtn = {"Total_Price" : total_price, "Price_Per_Share" : Price_Per_Share, "Trades" : pd.DataFrame(trades),
          "Shortfall" : total_shares - shares, "filtered_data" : filtered_data, 
          "Price_Impact" : Price_Per_Share - curr_price[0]}
    return rtn
result = VWAP_Trade_Cost("20181123", "1300", 200151, "JNJ", 0.1)
print("total traded price : ", result[ "Total_Price" ])
print("average traded price : ", result[ "Price_Per_Share" ])
print("Price Impact : ", result[ "Price_Impact" ])
print(result[ "Trades" ])