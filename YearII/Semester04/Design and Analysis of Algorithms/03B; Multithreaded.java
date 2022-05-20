package com.vtucse_iv;

import java.util.*;

class Cube implements Runnable {
	public int x;
	public Cube(int x) {
		this.x = x;
	}
	public void run() {
		System.out.println("From third thread-Cube of" + x + "is:" + x * x * x);
	}
}
class Square implements Runnable {
	public int x;
	public Square(int x) {
		this.x = x;
	}
	public void run() {
		System.out.println("From second thread-Square of" + x + "is:" + x * x);
	}
}
class FirstThreadIsRandom extends Thread {
	public void run() {
		int num = 0;
		Random r = new Random();
		try {
			for (int i = 0; i<5; i++) {
				num = r.nextInt(100);
				System.out.println("Main Thread Started and Generated Number is" + num);
				Thread t2 = new Thread(new Square(num));
				t2.start();
				Thread t3 = new Thread(new Cube(num));
				t3.start();
				Thread.sleep(1000);
				System.out.println("-------------------------------------------------");
			}
		} catch (Exception ex) {
			System.out.println(ex.getMessage());
		}
	}
}
public class MultiThreaded {
	public static void main(String[] args) {
		FirstThreadIsRandom firstThread = new FirstThreadIsRandom();
		Thread t1 = new Thread(firstThread);
		t1.start();
	}
}