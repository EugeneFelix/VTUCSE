import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class TCPClient {
	public void main(String[] args) throws IOException {
		Socket sock = new Socket("127.0.0.1", 4000);
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader socketRead = new BufferedReader(new InputStreamReader(sock.getInputStream()));
		PrintWriter pWrite = new PrintWriter(sock.getOutputStream(), true);
		System.out.print("Enter file name...");
		String fName = keyRead.readLine();
		pWrite.println(fName);
		String str;
		while ((str = socketRead.readLine()) != null)
			System.out.println(str);
		sock.close();
	}
}