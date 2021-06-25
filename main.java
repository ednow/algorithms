import PTA.PTA1003.*;
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
        JSONObject object = (JSONObject) JSONObject.parse(tools.readToString(path.toString()));
        assert object != null;
        Emergency e = new Emergency();
        e.rectifyInput(tools.stringToInputStream(object.getString("data")));
        String result = e.rectifyData(e.solution(e.getSource(), e.getDestination()));
        assertEquals(object.get("answer"), result);
    }
}
