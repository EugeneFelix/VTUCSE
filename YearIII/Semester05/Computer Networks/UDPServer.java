import static java.lang.System.out;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class UDPServer {
	public void main(String[] args) throws IOException {
		DatagramSocket datagramSocket = new DatagramSocket(9876);
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		byte[] receiveData = new byte[1024];
		DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
		datagramSocket.receive(receivePacket);
		String sentence = new String(receivePacket.getData());
	    out.println("RECEIVED: " + sentence);
		out.println("Enter the message:");
		String data = bufferedReader.readLine();
		datagramSocket.send(new DatagramPacket(data.getBytes(), data.getBytes().length, receivePacket.getAddress(), receivePacket.getPort()));
		datagramSocket.close();
	}
}