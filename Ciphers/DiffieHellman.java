import java.math.BigInteger;
import java.io.*;

class DiffieHellman {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter p:");
		BigInteger p = new BigInteger(br.readLine());
		System.out.println("Enter q:");
		BigInteger q = new BigInteger(br.readLine());
		// Alice
		System.out.println("Enter a:");
		BigInteger a = new BigInteger(br.readLine());
		BigInteger A = q.modPow(a, p);
		System.out.println("A: " + A);
		// Bob
		System.out.println("Enter b:");
		BigInteger b = new BigInteger(br.readLine());
		BigInteger B = q.modPow(b, p);
		System.out.println("B: " + B);
		// Send B to Alice
		BigInteger AliceKey = B.modPow(a, p);
		System.out.println("AliceKey: " + AliceKey);
		// Send A to Bob
		BigInteger BobKey = A.modPow(b, p);
		System.out.println("BobKey: " + BobKey);
	}
}