import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class crcCCITT {
	public void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter no. of message bits:");
        int message_bits = Integer.parseInt(br.readLine());
		int[] message = new int[message_bits];
        System.out.println("Enter message:");
        for(int i=0; i<message_bits; i++)
            message[i] = Integer.parseInt(br.readLine());

        System.out.println("Enter no. of generator bits:");
        int gen_bits = Integer.parseInt(br.readLine());

        int[] gen = new int[gen_bits];
        System.out.println("Enter generator bits:");
        for(int i=0; i<gen_bits; i++)
            gen[i] = Integer.parseInt(br.readLine());
        int total_bits = message_bits + gen_bits - 1;
        int [] app_message = new int[total_bits];
        int[] rem = new int[total_bits];
        int[] trans_message = new int[total_bits];
        for(int i=0; i<message.length; i++)
            app_message[i] = message[i];

        System.out.println("Entered message:");
        for(int i= 0; i<message.length; i++)
            System.out.print(message[i] + " ");
        System.out.println();

        System.out.println("Appended message:");
        for(int i=0; i<app_message.length; i++)
            System.out.print(app_message[i] + " ");
        System.out.println();

        System.out.println("Generator bits:");
        for(int i=0; i<gen.length; i++)
            System.out.print(gen[i] + " ");
        System.out.println();

        for(int i=0; i<app_message.length; i++)
            rem[i] = app_message[i];
        rem = computecrc(gen, rem);
        for(int i=0; i<app_message.length; i++)
            trans_message[i] = (app_message[i] ^ rem[i]);

        System.out.println("Transmitted message from the transmitter:");
        for(int i=0; i<trans_message.length; i++)
            System.out.print(trans_message[i] + " ");
        System.out.println();
        System.out.println("Enter received message:");
        for(int i=0; i<trans_message.length; i++)
            trans_message[i] = Integer.parseInt(br.readLine());

        System.out.println("Message of " + total_bits + " bits received.");
        System.out.println("Received message is:");
        for(int i=0; i<trans_message.length; i++)
            System.out.print(trans_message[i] + " ");
        System.out.println();
        for(int i=0; i<trans_message.length; i++)
            rem[i] = trans_message[i];
        rem = computecrc(gen, rem);

        for(int i=0; i<rem.length; i++) {
            if(rem[i] == 1) {
                System.out.println("There is an error");
                break;
            }

            if(i == rem.length - 1)
                System.out.println("There is no error");
        }
        
    }
	public static int[] computecrc(int[] gen, int[] rem) {
        int current = 0;
        int i;
        while(true) {
            for(i=0; i<gen.length; i++)
                rem[current + i] = (rem[current + i] ^ gen[i]);

            while((rem[current] == 0) && (current != rem.length - 1))
                current++;

            if((rem.length - current) < gen.length)
                break;
        }
        return rem;
    }
}