class VigenereCipher {
	public static String encrypt(String plainText, String key) {
		String result = "";
		for (int i = 0, j = 0; i < plainText.length(); i++) {
			char ch = plainText.charAt(i);
			result += (char)(((int)ch + key.charAt(j) - 2 * 65) % 26 + 65);
			j = (++j) % key.length();
		}
		return result;
	}

	public static String decrypt(String cipherText, String key) {
		String result = "";
		for (int i = 0, j = 0; i < cipherText.length(); i++) {
			char ch = cipherText.charAt(i);
			result += (char)(((int)ch - key.charAt(j) + 26) % 26 + 65);
			j = (++j) % key.length();
		}
		return result;
	}

	public static void main(String[] args) {
		String key = "AYUSH";
		String str = "GEEKSFORGEEKS";
		String cipherText = encrypt(str, key);
		System.out.println(cipherText);
		System.out.println(decrypt(cipherText, key));
	}
}