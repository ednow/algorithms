import PTA.PTA1003.*;
import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import org.junit.Test;
import utils.tools;

import java.nio.file.Path;
import java.nio.file.Paths;

import static org.junit.Assert.assertEquals;



public class main {
    @Test
    public void testEmergency(){
        Path path = Paths.get("PTA", "PTA1003", "data.json");
        JSONArray testCases = (JSONArray) JSONObject.parse(tools.readToString(path.toString()));
        assert testCases != null;
        Emergency e = new Emergency();
        for (Object o:testCases) {
            JSONObject testCase = (JSONObject) o;
            e.rectifyInput(tools.stringToInputStream(testCase.getString("data")));
            String result = e.rectifyData(e.solution(e.getSource(), e.getDestination()));
            assertEquals(testCase.get("answer"), result);
        }


    }
}
