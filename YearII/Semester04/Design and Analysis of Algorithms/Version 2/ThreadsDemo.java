import java.util.*;
class rThread extends Thread {
	public void run() {
		int a;
		Random rand = new Random();
		for (int i = 0; i < 10; i++) {
			a = rand.nextInt(100);
			System.out.println("Random number is" + a);
			Thread thread2 = new squareNum(a);
			thread2.start();
			Thread thread3 = new cubeNum(a);
			thread3.start();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

class squareNum extends Thread {
	int n;
	squareNum(int a) {
		n = a;
	}
	public void run() {
		System.out.println("Square of the number " + n + " is: " + Math.pow(n, 2));
	}
}

class cubeNum extends Thread {
	int n;
	cubeNum(int a) {
		n = a;
	}
	public void run() {
		System.out.println("\nCube of the number " + n + " is: " + Math.pow(n, 3));
	}
}


public class ThreadsDemo {
	public void main(String[] args) {
		Thread thread1 = new rThread();
		thread1.start();
	}
}