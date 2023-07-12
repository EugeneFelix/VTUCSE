## 18CSMP68 - Mobile Application Development
### List of experiments
#### 1. Visiting Card
#### 2. Calculator
	+ Integer.parseInt();
	+ e.getText().toString();
	+ tv.setText();

#### 3. Login Signup
	+ Intents = (ACTION + data + type (spécialisé)):
		- .this .class
		- startActivity()
		- getIntent().getStringExtra("")
	+ setEnabled(false)

#### 4. Wallpaper Changer
	+ BMFact.decodeRes(getRess, array[nextIdx]);
	+ WallpaperManager.getInst(this)
	+ wpm.setBitmap()

#### 5. Counter
	+ postDelayed(this, delay)
	+ removeCallbacks(Thread)
	+ Runnable

#### 6. JSON & XML Parser
	+ XML W3C.ORG.DOM
		- javax.xml.parsers.Doc;
		- NodeList.getLength().item(i)
	+ org.JSON
		- jarr.getJSONObject(idx)
		- jo.getString("")
#### 7. TTS
	+ TTS(getAppContext, onInit(status)Listener)
	+ java.util.Locale
	+ tts.speak(str, qflsh, BundleNULL)

#### 8. Call and Save
	+ Intents = (ACTION + data + type (spécialisé)):
		- setType CONTENT_TYPE
		- putExtra Intents.Insert.PHONE num
		- setData Uri.parse(tel)
	+ Cast to Button and setText()

### Général
1. edittext.getText().toString();
2. Toast.makeText(CLASS.this, "MSG", Toast.LENGTH_LONG-SHORT).show();