class AffineCipher {
	public static String encrypt(String plainText, int x, int y) {
		String result = "";
		for (int i = 0; i < plainText.length(); i++) {
			char ch = plainText.charAt(i);
			result += (char)((x * (ch - 65) + y) % 26 + 65);
		}
		return result;
	}

	public static String decrypt(String cipherText, int x, int y) {
		String result = "";
		int x_inverse = 0;
		int flag = 0;
		for (int i = 0; i <= 25; i++) {
			flag = (x * i) % 26;
			if (flag == 1) {
				x_inverse = i;
				break;
			}
		}
		for (int i = 0; i < cipherText.length(); i++) {
			char ch = cipherText.charAt(i);
			result += (char)((x_inverse * (ch - y + 65)) % 26 + 65);
		}
		return result;
	}

	public static void main(String[] args) {
		System.out.println("AFFINE");
		System.out.println(encrypt("AFFINE", 17, 20));
		System.out.println(decrypt(encrypt("AFFINE", 17, 20), 17, 20));
	}
}