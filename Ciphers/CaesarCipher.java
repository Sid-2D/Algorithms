class CaesarCipher {
	public static StringBuffer encrypt(String plainText, int s) {
		StringBuffer result = new StringBuffer();
		for (int i = 0; i < plainText.length(); i++) {
			if (Character.isUpperCase(plainText.charAt(i))) {
				char ch = (char)(((int)plainText.charAt(i) + s - 65) % 26 + 65);
				result.append(ch);
			} else {
				char ch = (char)(((int)plainText.charAt(i) + s - 97) % 26 + 97);
				result.append(ch);
			}
		}
		return result;
	}

	public static void main(String args[]) {
		String text = "XYZA";
		int s = 2;
		System.out.println(encrypt(text, s));
	}
}