class HillCipher {
	public static int[][] keyMat = new int[][] {
		{ 1, 2, 1 },
		{ 2, 3, 2 },
		{ 2, 2, 1 }
	};

	public static int[][] invKeyMat = new int[][] {
		{ -1, 0, 1 },
		{ 2, -1, 0 },
		{ -2, 2, -1 }
	};

	public static String key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	public static void main(String[] args) {
		String plainText = "SECRETHILLCIPHERTEXT";
		String result = "";
		int n = plainText.length() % 3;
		if (n != 0) {
			for (int i = 0; i < (3 - n); i++) {
				plainText += 'X';
			}
		}
		// Encrypt
		for (int i = 0; i < plainText.length(); i += 3) {
			result += encrypt(plainText.charAt(i), plainText.charAt(i + 1), plainText.charAt(i + 2));
		}
		System.out.println(result);
		// Decrypt
		String decryptString = "";
		for (int i = 0; i < result.length(); i += 3) {
			decryptString += decrypt(result.charAt(i), result.charAt(i + 1), result.charAt(i + 2));
		}
		System.out.println(decryptString);
	}

	public static String encrypt(char a, char b, char c) {
		int x, y, z;
		int posA = (int)a - 65;
		int posB = (int)b - 65;
		int posC = (int)c - 65;
		x = posA * keyMat[0][0] + posB * keyMat[1][0] + posC * keyMat[2][0];
		y = posA * keyMat[0][1] + posB * keyMat[1][1] + posC * keyMat[2][1];
		z = posA * keyMat[0][2] + posB * keyMat[1][2] + posC * keyMat[2][2];
		a = key.charAt(x % 26);
		b = key.charAt(y % 26);
		c = key.charAt(z % 26);
		String result = "" + a + b + c;
		return result;
	}

	public static String decrypt(char a, char b, char c) {
		int x, y, z;
		int posA = (int)a - 65;
		int posB = (int)b - 65;
		int posC = (int)c - 65;
		x = posA * invKeyMat[0][0] + posB * invKeyMat[1][0] + posC * invKeyMat[2][0];
		y = posA * invKeyMat[0][1] + posB * invKeyMat[1][1] + posC * invKeyMat[2][1];
		z = posA * invKeyMat[0][2] + posB * invKeyMat[1][2] + posC * invKeyMat[2][2];
		a = key.charAt(x % 26 < 0 ? 26 + x % 26 : x % 26);
		b = key.charAt(y % 26 < 0 ? 26 + y % 26 : y % 26);
		c = key.charAt(z % 26 < 0 ? 26 + z % 26 : z % 26);
		String result = "" + a + b + c;
		return result;
	}
}