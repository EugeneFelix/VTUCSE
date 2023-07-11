package com.nono.exchange;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.*;
import org.json.JSONArray;
import org.json.JSONObject;
import org.w3c.dom.*;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class MainActivity extends AppCompatActivity {
	TextView display;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		display = findViewById(R.id.display);
	}
	public void parsexml(View v) {
		try {
			InputStream istream = getAssets().open("city.xml");
			DocumentBuilder builder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
			Document document = builder.parse(istream);
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.append("XML DATA");
			stringBuilder.append("\n-------------");
			NodeList nodeList = document.getElementsByTagName("place");
			for (int i = 0; i < nodeList.getLength(); i++) {
				Node node = nodeList.item(i);
				if (node.getNodeType() == Node.ELEMENT_NODE) {
					Element element = (Element) node;
					stringBuilder.append("\n Name:").append(getValue("name", element));
					stringBuilder.append("\n Latitude:").append(getValue("lat", element));
					stringBuilder.append("\n Longitude:").append(getValue("long", element));
					stringBuilder.append("\n Temperature: ").append(getValue("temperature", element));
				}
			}
			display.setText(stringBuilder.toString());
		} catch (Exception e) {
			e.printStackTrace();
			Toast.makeText(MainActivity.this, "Exception! See LOGS!", Toast.LENGTH_LONG).show();
		}
	}

	public void parsejson(View V) {
		StringBuilder stringBuilder = new StringBuilder();
		try {
			InputStream istream = getAssets().open("city.json");
			byte[] buffer = new byte[istream.available()];
			istream.read(buffer);
			String json = new String(buffer, StandardCharsets.UTF_8);
			JSONArray jsonArray = new JSONArray(json);
			stringBuilder.append("JSON DATA");
			stringBuilder.append("\n--------");
			for (int i = 0; i < jsonArray.length(); i++) {
				JSONObject jsonObject = jsonArray.getJSONObject(i);
				stringBuilder.append("\n Name:").append(jsonObject.getString("name"));
				stringBuilder.append("\n Latidue:").append(jsonObject.getString("lat"));
				stringBuilder.append("\n Longitude:").append(jsonObject.getString("long"));
				stringBuilder.append("\n Temperature: ").append(jsonObject.getString("temperature"));
				stringBuilder.append("\n Humidity: ").append(jsonObject.getString("humidity"));
				stringBuilder.append("\n--------------");
			}
			display.setText(stringBuilder.toString());
			istream.close();
		} catch (Exception e) {
			e.printStackTrace();
			Toast.makeText(MainActivity.this, "Exception! See LOGS!", Toast.LENGTH_LONG).show();
		}
	}
	private String getValue(String tag, Element element) {
		return element.getElementsByTagName(tag).item(0).getFirstChild().getNodeValue();
	}
}

/*
[
	{
		"name":"HASSAN",
		"lat":"12.295",
		"long":"76.639",
		"temperature":"22",
		"humidity":"92%"
	},
	{
		"name":"MANDYA",
		"lat":"10.11",
		"long":"66.639",
		"temperature":"24",
		"humidity":"82%"
	}
]
*/

/*
<?xml version="1.0"?>
<records>
	<place>
		<name>Mysore</name>
		<lat>12.295</lat>
		<long>76.639</long>
		<temperature>22</temperature>
		<humidity>90%</humidity>
	</place>
	<place>
		<name>Bangalore</name>
		<lat>13.295</lat>
		<long>77.639</long>
		<temperature>25</temperature>
		<humidity>74%</humidity>
	</place>
</records>
*/