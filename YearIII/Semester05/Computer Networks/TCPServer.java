import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class TCPServer {
	public void main(String[] args) throws IOException {
		ServerSocket sersock = new ServerSocket(4000);
		Socket sock = sersock.accept();
		BufferedReader fileRead = new BufferedReader(new InputStreamReader(sock.getInputStream()));
		BufferedReader contentRead = new BufferedReader(new FileReader(fileRead.readLine()));
		PrintWriter pWrite = new PrintWriter(sock.getOutputStream(), true);
		System.out.println("Server ready for connection and waiting for messages...");
		String str;
		while ((str = contentRead.readLine()) != null)
			pWrite.println(str);
		contentRead.close();
		sersock.close();
	}
}