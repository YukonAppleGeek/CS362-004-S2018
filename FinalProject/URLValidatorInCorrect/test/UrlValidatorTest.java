

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!
public class UrlValidatorTest extends TestCase {

    public UrlValidatorTest(String testName) {
      super(testName);
   }

    public void testManualTest()
    {
        UrlValidator validator = new UrlValidator();

        assertFalse(validator.isValid("http:/test.com"));
        // Fails
        assertTrue(validator.isValid("http://test.com/page"));
        // Fails
        assertTrue(validator.isValid("http://test.com/pages/"));
        assertFalse(validator.isValid("://test"));
        assertTrue(validator.isValid("ftp://test.co"));
        assertFalse(validator.isValid("ftp"));
    }
   

    // Validate scheme
    public void testYourFirstPartition()
    {
        UrlValidator validator = new UrlValidator();

        // Fail
        assertTrue(validator.isValid("http://test.com"));
        assertFalse(validator.isValid("http:/test.com"));
        // Fail
        assertTrue(validator.isValid("h1p://test.com"));
        assertFalse(validator.isValid("://test.com"));
        // Fail
        assertTrue(validator.isValid("ftp://test.com"));

    }

    // Validate authority
    public void testYourSecondPartition()
    {
        UrlValidator validator = new UrlValidator();
        String urlScheme = "http://";

        // Fail
        assertTrue(validator.isValid(urlScheme + "1.1.1.1"));
        // Fail
        assertTrue(validator.isValid(urlScheme + "www.test.com"));
        assertFalse(validator.isValid(urlScheme + "test.a"));
        // Fail
        assertTrue(validator.isValid(urlScheme + "test1.com"));

    }

    public void testIsValid() {

        // Test arrays are from URLValidatorCorrect.java
        ResultPair[] testUrlScheme = {new ResultPair("http://", true),
                new ResultPair("ftp://", true),
                new ResultPair("h3t://", true),
                new ResultPair("3ht://", false),
                new ResultPair("http:/", false),
                new ResultPair("http:", false),
                new ResultPair("http/", false),
                new ResultPair("://", false),
                new ResultPair("", true)};

        ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
                new ResultPair("go.com", true),
                new ResultPair("go.au", true),
                new ResultPair("0.0.0.0", true),
                new ResultPair("255.255.255.255", true),
                new ResultPair("256.256.256.256", false),
                new ResultPair("255.com", true),
                new ResultPair("1.2.3.4.5", false),
                new ResultPair("1.2.3.4.", false),
                new ResultPair("1.2.3", false),
                new ResultPair(".1.2.3.4", false),
                new ResultPair("go.a", false),
                new ResultPair("go.a1a", false),
                new ResultPair("go.1aa", false),
                new ResultPair("aaa.", false),
                new ResultPair(".aaa", false),
                new ResultPair("aaa", false),
                new ResultPair("", false)};

        ResultPair[] testUrlPort = {new ResultPair(":80", true),
                new ResultPair(":65535", true),
                new ResultPair(":0", true),
                new ResultPair("", true),
                new ResultPair(":-1", false),
                new ResultPair(":65636", false),
                new ResultPair(":65a", false)};

        ResultPair[] testPath = {new ResultPair("/test1", true),
                new ResultPair("/t123", true),
                new ResultPair("/$23", true),
                new ResultPair("/..", false),
                new ResultPair("/../", false),
                new ResultPair("/test1/", true),
                new ResultPair("", true),
                new ResultPair("/test1/file", true),
                new ResultPair("/..//file", false),
                new ResultPair("/test1//file", false)
        };
        //Test allow2slash, noFragment
        ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
                new ResultPair("/t123", true),
                new ResultPair("/$23", true),
                new ResultPair("/..", false),
                new ResultPair("/../", false),
                new ResultPair("/test1/", true),
                new ResultPair("/#", false),
                new ResultPair("", true),
                new ResultPair("/test1/file", true),
                new ResultPair("/t123/file", true),
                new ResultPair("/$23/file", true),
                new ResultPair("/../file", false),
                new ResultPair("/..//file", false),
                new ResultPair("/test1//file", true),
                new ResultPair("/#/file", false)
        };

        ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
                new ResultPair("?action=edit&mode=up", true),
                new ResultPair("", true)
        };
        UrlValidator validator = new UrlValidator();

        int i, j, k, m;
        for (i = 0; i<testUrlScheme.length; i++) {
            for (j = 0; j<testUrlAuthority.length; j++) {
                for (k = 0; k<testUrlPort.length; k++) {
                    for (m = 0; m<testPath.length; m++) {
                        String url = testUrlScheme[i].url + testUrlAuthority[j].url + testUrlPort[k].url + testPath[m].url;
                        boolean valid = testUrlScheme[i].valid && testUrlAuthority[j].valid && testUrlPort[k].valid && testPath[m].valid;
                        if(validator.isValid(url) != valid){
                            System.out.println("Invalid string: URL " + url + " EXPECTED " + valid + " FAILED ");
                        }
                    }
                }
            }
        }
    }

    public class ResultPair {
        String url;
        boolean valid;

        public ResultPair(String url, boolean valid){
            this.url = url;
            this.valid = valid;
        }
    }
}
