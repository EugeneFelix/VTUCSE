package com.vtucse_iv;

import java.util.Scanner; import java.util.StringTokenizer;
class Customer {
private String customerName,date; public Customer(String customerName, String date) {
super();
this.customerName = customerName; this.date = date;
} @Override
public String toString() {
String returnValue = customerName+","; StringTokenizer tokenizer = new StringTokenizer(date,"/"); System.out.println("The Customer details are "); while(tokenizer.hasMoreTokens()) {
returnValue = returnValue+tokenizer.nextToken(); if(tokenizer.hasMoreElements()) {
returnValue = returnValue+","; }
} return returnValue;
} }
public class CustomerDetails {
public static void main(String[] args) {
String customerName;String date; Scanner scanner = new Scanner(System.in); System.out.println("Enter customer name"); customerName = scanner.next(); System.out.println("Enter Date (dd/mm/yyy)"); date = scanner.next(); Customer customer = new Customer(customerName,date); System.out.println(customer.toString());
} }