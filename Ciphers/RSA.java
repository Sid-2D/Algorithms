import java.math.BigInteger;
import java.security.SecureRandom;

class RSA {
	private static BigInteger one = new BigInteger("1");
	private static BigInteger n;
	private static BigInteger phi;
	private static BigInteger e;
	private static BigInteger d;
	public RSA() {
		BigInteger p = BigInteger.probablePrime(40, new SecureRandom());
		BigInteger q = BigInteger.probablePrime(40, new SecureRandom());
		n = p.multiply(q);
		phi = (p.subtract(one)).multiply(q.subtract(one));
		e = new BigInteger("65537");
		d = e.modInverse(phi);
	}
	public BigInteger encrypt(BigInteger msg) {
		return msg.modPow(e, n);
	}
	public BigInteger decrypt(BigInteger msg) {
		return msg.modPow(d, n);
	}
	public static void print() {
		System.out.println("Public key: " + e.longValue() + "\nPrivate key: " + d.longValue() + "\nModuli: " + n.longValue());
	}
	public static void main(String[] args) {
		RSA rsa = new RSA();
		rsa.print();
		String msg = "BEIT";
		System.out.println("Plaintext: " + msg);
		BigInteger plainText = new BigInteger(msg.getBytes());
		BigInteger cipherText = rsa.encrypt(plainText);
		System.out.println("Encrypted message:" + cipherText);
		BigInteger decoded = rsa.decrypt(cipherText);
		System.out.println("Encrypted message:" + new String(decoded.toByteArray()));
	}
}